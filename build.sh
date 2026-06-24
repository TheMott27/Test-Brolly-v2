#!/bin/bash
# Increment patch version in package.json
python3 -c "
import json
with open('package.json') as f:
    d = json.load(f)
parts = d['version'].split('.')
parts[2] = str(int(parts[2]) + 1)
d['version'] = '.'.join(parts)
with open('package.json', 'w') as f:
    json.dump(d, f, indent=2)
print('Version:', d['version'])
"
pebble clean && pebble build
VERSION=$(python3 -c "import json; print(json.load(open('package.json'))['version'])")
cp build/brolly.pbw ~/Downloads/"Brolly v${VERSION}.pbw"
echo "Built: Brolly v${VERSION}.pbw"
