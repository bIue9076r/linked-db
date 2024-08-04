# Linked D(ata) B(ase)
Shoddy implementation of a linked list database

#### Custom Data Types
```
offset_t = unsigned long long int;
boolean_t = unsigned int;
```

#### Constants
```
MAGIC = 0x13311331
LOOKUP_MAX = 255
INDEX_MAX = 16
VALUE_MAX = 255
```

##### Header:
```
unsigned int magic;
unsigned int version;
offset_t size;
offset_t lookup[LOOKUP_MAX];
```

#### Node:
```
offset_t back;
offset_t next;
char index[INDEX_MAX];
char value[VALUE_MAX];
boolean_t first;
```

# Example File
#### head:
```
MAGIC;  // Magic
0x0;  // Version
0x0A58;  // File Size
{0x0 ... ['T'] = 0x808 ... 0x0}; // Node Look Up Table
```
### node1:
```
0x0;  // Back Node
0x930;  // Next Node
"Test1";  // Index
{0xFF ... 0xFF};  // Value
0x1;  // First?
```
### node2:
```
0x808;  // Back Node
0x0;  // Next Node
"Test2";  // Index
{0xEE ... 0xEE};  // Value
0x0;  // First?
```
