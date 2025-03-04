#!/bin/bash

# ensure the executable exists
if [ ! -f ./money_converter ]; then
    echo "Error: Executable not found! Run 'make' first."
    exit 1
fi

# create  test input file
cat <<EOF > test_input.txt
4734
99
120000
1
1300
50000
-100
99
200000
EOF

# expected out for comp
cat <<EOF > expected_output.txt
4734 = forty-seven dollars and thirty-four cents
99 = ninety-nine cents
120000 = one thousand two hundred dollars
1 = one cent
1300 = thirteen dollars
50000 = five hundred dollars
-100 = Invalid amount
99 = ninety-nine cents (cached)
200000 = two thousand dollars
EOF

# run program and store  output
./money_converter < test_input.txt > test_output.txt

# comp  output to  expected output
if diff -q test_output.txt expected_output.txt > /dev/null; then
    echo "All tests passed!"
    rm test_input.txt test_output.txt expected_output.txt
    exit 0
else
    echo "Tests failed! Differences found:"
    diff test_output.txt expected_output.txt
    exit 1
fi
