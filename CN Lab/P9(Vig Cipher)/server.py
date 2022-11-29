import socket as so
s = so.socket()

print("socket made")


port = 1234

s.bind(('localhost', port))

s.listen(3)

print('waiting for connection')


def generateKey(string, key):
    key = list(key)
    if len(string) == len(key):
        return (key)
    else:
        for i in range(len(string) -
                       len(key)):
            key.append(key[i % len(key)])
    return ("" . join(key))


# while True:
c, addr = s.accept()
datarecv = c.recv(1024).decode()

print("Ciphertext :", datarecv)
keyNew = input('Enter key to decrypt : ')
key = generateKey(datarecv, keyNew)


def originalText(cipher_text, key):
    orig_text = []
    # print("Test 1")
    for i in range(len(cipher_text)):
        x = (ord(cipher_text[i]) - ord(key[i]) + 26) % 26
        x += ord('A')
        orig_text.append(chr(x))
    return ("" . join(orig_text))

    # cipher_text =str(datarecv)
    
print("Original/Decrypted Text : \n")
print(originalText(datarecv, key))
c.close()
