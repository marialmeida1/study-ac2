# Função que converte um número em string para sua representação hexadecimal
def hex(letter):
    codehex = {
        '1': '1', # Cada número possuí seu correspondente
        '0': '0',
        '2': '2',
        '3': '3',
        '4': '4',
        '5': '5',
        '6': '6',
        '7': '7',
        '8': '8',
        '9': '9',
        '10': 'A', # A partir do 10 esse valor é representado por letras
        '11': 'B',
        '12': 'C',
        '13': 'D',
        '14': 'E',
        '15': 'F'
    }

    # Retorna a conversão correspondente ou uma mensagem de erro se a chave não existir
    return codehex.get(letter, "Invalid Option")



# Função que converte uma expressão mnemônica para seu valor hexadecimal correspondente
def mnemonico(expression):
    codehex = {
        'zeroL': '1',
        'umL': '0',
        'copiaA': '2',
        'copiab': '3',
        'nA': '4',
        'nB': '5',
        'AenB': '6',
        'nAeB': '7',
        'AxB': '8',
        'nAxnB': '9',
        'nAxnBn': 'A',
        'AeB': 'B',
        'AeBn': 'C',
        'AoBn': 'D',
        'AoB': 'E',
        'nAonBn': 'F'
    }

    # Retorna o valor correspondente ou uma mensagem de erro se a chave não existir
    return codehex.get(expression, "Invalid Option")



# Função que escreve no arquivo de saída os valores convertidos para hexadecimal
def writeFile(x, y, w):
    outfile.write(f"{hex(x)}{hex(y)}{mnemonico(w)}\n") # Escreve no formato hexadecimal



# Abre os arquivos: um para leitura ('testeula.ula') e outro para escrita ('testeula.hex')
with open ('testeula.ula', 'r') as infile, open ('testeula.hex', 'w') as  outfile:

    # Variáveis iniciais
    x = '0'
    y = '0'
    w = '0'

    for line in infile: # Lê cada linha do arquivo de entrada

        # Verifica se a linha começa com 'X' e extrai seu valor
        if(line[0] == 'X'):
            x = line.replace("X=", "").replace(";", "").replace("\n", "")

        # Verifica se a linha começa com 'Y' e extrai seu valor
        if(line[0] == 'Y'):
            y = line.replace("Y=", "").replace(";", "").replace("\n", "")

        # Verifica se a linha começa com 'W' e extrai seu valor
        if(line[0] == 'W'):
            w = line.replace("W=", "").replace(";", "").replace("\n", "")
            writeFile(x, y, w)  # Com todos as variáveis capturadas ele pode executar a função e escrever no arquivo de saída