import boto3
import base64
from Crypto.Cipher import AES

BLOCK_SIZE = 32
PADDING = '|'

key_arn = '{{ arn:aws:kms:ap-northeast-2:611089428855:key/03703854-534e-40ec-838c-cf65541f88f8 }}'
message = 'https://www.naver.com'

client = boto3.client('kms')

data_key = client.generate_data_key(
    KeyId=key_arn,
    KeySpec='AES_256'
)

pad = lambda s: s + (BLOCK_SIZE - len(s) % BLOCK_SIZE) * PADDING

plaintext_key = data_key.get('Plaintext')
encrypted_key = data_key.get('CiphertextBlob')

###### Encrypted data ######## 
encryptor = AES.new(plaintext_key)
encrypted_data = base64.b64encode(encryptor.encrypt(pad(message)))

print("########## Encrypted Data ##############")
print(encrypted_data)

###### Decrypted data ######## 
decrypted_key = client.decrypt(CiphertextBlob=encrypted_key).get('Plaintext')
decryptor = AES.new(decrypted_key)

decrypted_str = decryptor.decrypt(base64.b64decode(encrypted_data)).decode('utf-8')

print("########## Decrypted Data ##############")
print(decrypted_str.rstrip(PADDING))