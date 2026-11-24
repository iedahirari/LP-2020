"""Testes de console: python tests/test_programas.py build/Debug."""
from pathlib import Path
import subprocess
import sys

BIN = Path(sys.argv[1] if len(sys.argv) > 1 else "build").resolve()
CHECKS = 0


def run(name, lines):
    global CHECKS
    executable = BIN / (name + (".exe" if sys.platform == "win32" else ""))
    result = subprocess.run(
        [str(executable)], input=lines, text=True, encoding="utf-8",
        capture_output=True, timeout=5, check=True,
    )
    CHECKS += 1
    return result.stdout


# Sair, EOF e recuperacao de entradas numericas invalidas.
for name, exit_code in [("vetores", "4"), ("strings", "4"), ("consolidacao", "9")]:
    run(name, exit_code + "\n")
    run(name, "")
    out = run(name, "abc\n2x\n999999999999999999999\n" + exit_code + "\n")
    assert out.count("Digite um numero inteiro valido.") == 3
    assert "Opcao invalida." in run(name, "0\n" + exit_code + "\n")

# Os registros de produto, caminhao e cliente devem permanecer separados.
for name, back, listing in [("vetores", "5", "2"), ("strings", "6", "2")]:
    lines = ""
    for category, value in [("1", "A"), ("2", "B"), ("3", "C")]:
        lines += f"{category}\n1\n{value}\n{back}\n"
    for category in ("1", "2", "3"):
        lines += f"{category}\n{listing}\n{back}\n"
    out = run(name, lines + "4\n")
    for value in ("A", "B", "C"):
        assert out.count("Posicao 0: " + value) == 1, out

# Alterar, excluir o primeiro registro e reorganizar o vetor/matriz.
out = run("vetores", "1\n1\nA\n1\nB\n3\n1\nC\n4\n0\n2\n5\n4\n")
assert "Posicao 0: C" in out
out = run("strings", "1\n1\nAna\n1\nBia\n4\n1\nCris\n5\n0\n2\n3\nCris\n3\nBia\n6\n4\n")
assert out.count("Posicao 0: Cris") == 2
assert "Registro nao encontrado." in out

# Exclusao em vazio, indices negativos, limite superior e exclusao do ultimo.
for name, edit, delete, back in [("vetores", "3", "4", "5"), ("strings", "4", "5", "6")]:
    out = run(name, f"1\n{delete}\n0\n1\nA\n{edit}\n-1\n{delete}\n1\n{delete}\n0\n{delete}\n0\n{back}\n4\n")
    assert out.count("Posicao invalida.") == 4, out
    out = run(name, "1\n" + "1\nA\n" * 10 + f"1\n{back}\n4\n")
    assert out.count("Cadastro cheio.") == 1, out

# Textos invalidos nao devem consumir uma posicao nem truncar silenciosamente.
out = run("vetores", "1\n1\nAB\n1\n\n1\nZ\n2\n5\n4\n")
assert out.count("Texto invalido.") == 2
assert "Posicao 0: Z" in out
out = run("strings", "1\n1\n1234567890\n1\n   \n1\nNome 1234\n2\n6\n4\n")
assert out.count("Texto invalido.") == 2
assert "Posicao 0: Nome 1234" in out

# Revisoes: visitar todos os registros e incluir exatamente a fronteira de 1500 km.
out = run("consolidacao", "1\nNovo\n1499\n1\nLimite\n1500\n1\nUsado\n1501\n4\n3\nUsado\n3\nAusente\n9\n")
assert "Revisao: Novo" not in out
assert "Revisao: Limite - 1500 km" in out
assert "Revisao: Usado - 1501 km" in out
assert "Usado - 1501 km" in out
assert "Registro nao encontrado." in out
out = run("consolidacao", "1\nInvalido\n-1\n1\n" + "x" * 20 + "\n1\n1234567890123456789\n0\n2\n9\n")
assert "Quilometragem invalida." in out
assert "Texto invalido." in out
assert "Posicao 0: 1234567890123456789 - 0 km" in out
out = run("consolidacao", "1\nCarro\n0\n" * 10 + "1\n9\n")
assert out.count("Cadastro cheio.") == 1

print(f"OK: {CHECKS} execucoes de teste passaram.")
