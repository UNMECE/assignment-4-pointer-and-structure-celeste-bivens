#ifndef _MY_ITEM
#define _MY_ITEM

struct _Item
{
  double price;
  char *sku;
  char *name;
  char *category;
};
typedef struct _Item Item;

#endif 