import re

st = """
When should I use a List vs a LinkedList

Stack Overflow
https://stackoverflow.com › questions › when-should-i-...
Mehr 13, 1387 AP — List is array based collection (ArrayList). LinkedList is node-pointer based collection (LinkedListNode). On the API level usage, both of them ...
16 answers
 
·
 
Top answer: 
In most cases, List<T> is more useful. LinkedList<T> will have less cost when adding/removing ...
c# - Is List<T> a linked list? - Stack Overflow
Farvardin 14, 1391 AP
Difference between List<T> and LinkedList<T> - Stack ...
Azar 4, 1389 AP
Why C# list was implemented using array and not a linked ...
Tir 16, 1397 AP
What is the difference between a C# List<> and Linked List?
Dey 30, 1399 AP
More results from stackoverflow.com
"""
b = re.findAll('\d',st)
print(b)
