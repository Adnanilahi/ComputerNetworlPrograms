import socket as so

client = so.socket()
port = 1234

keyword = input('Enter the key for encryption : ')
# key = int(key)
client.connect(('localhost', port))


def generateKey(string, key):
    key = list(key)
    if len(string) == len(key):
        return (key)
    else:
        for i in range(len(string) -
                       len(key)):
            key.append(key[i % len(key)])
    return ("" . join(key))


def cipherText(string, key):
    cipher_text = []
    for i in range(len(string)):
        x = (ord(string[i]) +
             ord(key[i])) % 26
        x += ord('A')
        cipher_text.append(chr(x))
    return ("" . join(cipher_text))



string = input('Message to encrypt : ')
key = generateKey(string, keyword)
cipher_text = cipherText(string, key)


client.send(bytes(cipher_text, 'utf-8'))
