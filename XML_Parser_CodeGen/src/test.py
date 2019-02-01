import hashlib
m = hashlib.sha256(b"Connected").hexdigest()[:4]
print(m)