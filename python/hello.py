myorder = "she wants {0} pieces of item {2} for {1} dollars."

quantity = 3
itemno = 4
price = 10

print(myorder.format(quantity, itemno, price).find("pieces"))