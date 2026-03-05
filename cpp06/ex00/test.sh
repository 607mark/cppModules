#!/bin/bash

echo "=== PSEUDO-LITERALS ==="
echo "Test: nan"
./convert nan
echo ""
echo "Test: nanf"
./convert nanf
echo ""
echo "Test: +inf"
./convert +inf
echo ""
echo "Test: +inff"
./convert +inff
echo ""
echo "Test: -inf"
./convert -inf
echo ""
echo "Test: -inff"
./convert -inff
echo ""

echo "=== CHAR LITERALS ==="
echo "Test: 'a'"
./convert "'a'"
echo ""
echo "Test: 'Z'"
./convert "'Z'"
echo ""
echo "Test: '0'"
./convert "'0'"
echo ""
echo "Test: ' ' (space)"
./convert "' '"
echo ""
echo "Test: a (single letter without quotes)"
./convert a
echo ""

echo "=== INTEGER TESTS ==="
echo "Test: 0"
./convert 0
echo ""
echo "Test: -42"
./convert -42
echo ""
echo "Test: 42"
./convert 42
echo ""
echo "Test: 127 (char max unsigned)"
./convert 127
echo ""
echo "Test: 255 (unsigned char max)"
./convert 255
echo ""
echo "Test: 256 (unsigned char max + 1)"
./convert 256
echo ""
echo "Test: -128 (signed char min)"
./convert -128
echo ""
echo "Test: -129 (signed char min - 1)"
./convert -129
echo ""
echo "Test: 2147483647 (int max)"
./convert 2147483647
echo ""
echo "Test: 2147483648 (int max + 1)"
./convert 2147483648
echo ""
echo "Test: -2147483648 (int min)"
./convert -2147483648
echo ""
echo "Test: -2147483649 (int min - 1)"
./convert -2147483649
echo ""

echo "=== FLOAT TESTS ==="
echo "Test: 0.0f"
./convert 0.0f
echo ""
echo "Test: -4.2f"
./convert -4.2f
echo ""
echo "Test: 42.42f"
./convert 42.42f
echo ""
echo "Test: -0.0f"
./convert -0.0f
echo ""

echo "=== DOUBLE TESTS ==="
echo "Test: 0.0"
./convert 0.0
echo ""
echo "Test: -4.2"
./convert -4.2
echo ""
echo "Test: 42.42"
./convert 42.42
echo ""
echo "Test: -0.0"
./convert -0.0
echo ""

echo "=== EDGE CASES ==="
echo "Test: empty string"
./convert ""
echo ""
echo "Test: invalid (just text)"
./convert invalid
echo ""
echo "Test: 42f42 (invalid float)"
./convert 42f42
echo ""
echo "Test: --42 (double negative)"
./convert -- --42
echo ""
echo "Test: +42 (explicit positive)"
./convert +42
echo ""
echo "Test: .5 (no leading zero)"
./convert .5
echo ""
echo "Test: 5. (no trailing zero)"
./convert 5.
echo ""
