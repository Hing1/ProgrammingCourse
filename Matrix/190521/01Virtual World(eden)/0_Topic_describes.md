# Virtual World (eden)

## Descrption

This is a virtual world, none of us can tell whether it is real or not. But I need you now~

Now, you are require to build this world, first you should make 'person' and 'group'.

In the world, we can make group to invite persons or remove somone, make friends with others or break up with someone.

The rules of the world is inside the 'main.cpp', and the structure of 'world.h' is at the bottom of 'main.cpp'

## Hints

for 'person', when build a person, an ID would be arrange to him;

1. the ID is from 0 - 9900, the first should be 0 and the next will be 1бн;

for 'group', when build a group, an integer (0 or 1) is needed for initialization;

1. '0' means persons inside the group is strange to each other defaultly;
2. '1' means persons inside the group is already knowned to each other defaultly;

for 'displayGroup()', format is as the following:

1. Person_ID: ID sequence of the person's friends (early-make friend should be print first!)
2. example => Person_0: 0, 2
