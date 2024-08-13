#ifndef LDBT_H
#define LDBT_H
#include <stdio.h>

#define MAGIC 0x13311331
#define VERSION 0

#define LOOKUP_MAX 255
#define INDEX_MAX 16
#define VALUE_MAX 255

#define NODESIZE sizeof(node)
#define HEADERSIZE sizeof(header)

typedef unsigned long long int offset_t;

typedef unsigned int boolean_t;

typedef struct node_s {
	offset_t back;
	offset_t next;
	char index[INDEX_MAX];
	char value[VALUE_MAX];
	boolean_t first;
} node;

typedef struct return_node_s {
	boolean_t error;
	node node;
} return_node;

typedef struct header_s {
	unsigned int magic;
	unsigned int version;
	offset_t size;
	offset_t lookup[LOOKUP_MAX];
} header;

typedef struct return_header_s {
	boolean_t error;
	header header;
} return_header;


void snc(char* des, int l, char* src);
int stn(char* str);
int strequ(char* a, char* b);
void print_header(header* h);
void print_node(node* n);
node new_node(char in[INDEX_MAX], char v[VALUE_MAX]);
header new_header();
boolean_t db_exists(char* path);
boolean_t new_db(char* path)'
return_header read_db_head(char* path);
boolean_t db_entry_exists(char* path, char in[INDEX_MAX]);
boolean_t set_entry(char* path, char in[INDEX_MAX], char v[VALUE_MAX]);
return_node get_entry(char* path, char in[INDEX_MAX], char v[VALUE_MAX]);
#endif
