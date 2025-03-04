//create a structure for storing an item in a grocery store data base
struct _item{
	double price;
	char *sku;
	char *name;
	char *category;
};
typedef struct _item Item;
