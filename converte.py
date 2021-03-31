import docx2txt
import os

diretorio = os.getcwd()

arquivos = []  # Salva os nomes dos arquivos
saida = []  # Salva o nome dos arquivos sem o .docx
dados = []  # Salva os dados brutos
dadosFiltrados = []  # Salva os dados brutos sem '\n'

# Para cada arquivo .docx adiciona o nome em arquivo
for file in os.listdir(diretorio):
    if file.endswith('.docx'):
        arquivos.append(file)

for i in range(len(arquivos)):
    # Coloca os dados do arquivo na variavel
    dados.append(docx2txt.process(arquivos[i]))
    # Estava pulando duas vezes a linha pela leitura, portanto vou retirado o '\n' pula linha
    dadosFiltrados.append(dados[i].replace('\n', ""))
    # Tira o .docx do nome do arquivo
    saida.append(arquivos[i].replace(".docx", ""))
    # Coloca os dados no novo arquivo criado
    arquivo = open(saida[i] + '.txt', "w")
    for j in range(len(dadosFiltrados[i])):
        # Coloca caracter por caracter no arquivo
        arquivo.write(dadosFiltrados[i][j])
        # Da quebra de linha menos na ultima variavel
        if (j+1 != len(dadosFiltrados[i])):
            arquivo.write('\n')
    arquivo.close()
    #print(dadosFiltrados[i], file=arquivoDeTexto)
