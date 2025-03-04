# Test Case 1: basic amount - dollars and cents
Input:
4734

=== Expected Program Output ===
4734 = forty-seven dollars and thirty-four cents
====================
Result: PASS

---

# Test Case 2: only cents
Input:
99

=== Expected Program Output ===
99 = ninety-nine cents
====================
Result: PASS

---

# Test Case 3: even dollar amount
Input:
120000

=== Expected Program Output ===
120000 = one thousand two hundred dollars
====================
Result: PASS

---

# Test Case 4: smallest possible amount - 1 cent
Input:
1

=== Expected Program Output ===
1 = one cent
====================
Result: PASS

---

# Test Case 5: amt under 20 dollrs
Input:
1300

=== Expected Program Output ===
1300 = thirteen dollars
====================
Result: PASS

---

# Test Case 6: amt with exact hundred value
Input:
50000

=== Expected Program Output ===
50000 = five hundred dollars
====================
Result: PASS

---

# Test Case 7: invalid neg input
Input:
-100

=== Expected Program Output ===
-100 = Invalid amount
====================
Result: PASS

---

# Test Case 8: value should be cached
Input:
99

=== Expected Program Output ===
99 = ninety-nine cents (cached)
====================
Result: PASS

---

# Test Case 9: lrg amt - not memoized
Input:
200000

=== Expected Program Output ===
200000 = two thousand dollars
====================
Result: PASS
