import os
import sys
import json
from pathlib import Path
def main(dest: Path):
    out = {}
    files = Path(__file__).with_name('files').glob("*.cpp")
    for file in files:
        with open(str(file)) as f:
            body = f.read().splitlines()
        out[file.name] = {
            "prefix": file.stem,
            "body": body
        }
    print(dest)
    with open(str(dest), 'w') as f:
        json.dump(out, f)

if __name__ == "__main__":
    dest = Path.home() / '.config/Code/User/snippets/cpp.json'
    if len(sys.argv) > 1:
        dest = Path(sys.argv[1])
    main(dest)
