#include "item.h"
#include<stdio.h>
//adds items to an existing array
void add_item(Item *item_list, double price, char *sku, char *category,char *name, int index){
	item_list[index].price = price;
	item_list[index].sku =sku ;
	item_list[index].category = category;
	item_list[index].name = name;

}
void free_items(Item *item_list, int size){
	int i;
	for(i=0;i<size;i++){
		delete item_list[i].sku;
		delete item_list[i].name;
		delete item_list->category;
	}
	delete item_list;
}
double average_price(Item *item_list, int size){
	int i;
	double sum;
	for(i=0;i<size;i++){
		sum += item_list[i].price;
	}
	return sum/size;
}
//print items 
void print_items(Item *item_list, int size){
	int i;
	//need to fix use item-list some how
	for(i=0; i<size ;i++){
		printf("################\n");
		printf("item name = %d\n",item_list[i].name);
		printf("item sku = %d\n",item_list[i].sku);
		printf("item category = %d\n",item_list[i].category);
		printf("item price = %d\n",item_list[i].price);
		printf("################\n");
	}
}
int main(int argc, char *argv[]){
	char *sku_userIn = argv[1];
	int size=5;
	Item item_list[size];
	//adding 5 diffrent items
	add_item(&item_list, 6.70,"58930","grain","flour",0);	
	add_item(&item_list, 5.00,"02357","Dairy","iceCream",1);
	add_item(&item_list, 0.50,"50994","Fruit","apple",2);
	add_item(&item_list, 3.25,"37495","grain","rice",3);
	add_item(&item_list, 2.50,"97638","Dairy","milk",4);
	//find item using given SKU
	//using a while loop and print the item to the screen.
	//If not found, print item not found
	boolean found=false;
	int i=0;
	while(!found ||  i<size){
		if(strcmp(item_list[i].sku, search_sku) == 0){
			printf("Item Found\n");
			printf("###############\n");
			printf("item name = %d\n", item_list[i].name);
			printf("item sku = %d\n", item_list[i].sku);
			printf("item category = %d\n", item_list[i].category);
			printf("item price = %d\n", item_list[i].price);
			printf("###############\n");
			found = true;
			break;
		}
	if(!found){
		printf("Item not found");
	}
	print_items(&item_list, size);
	printf("average price of items = %d\n",average_price(&item_list, size));
	free_items(&item_list, size);
}
