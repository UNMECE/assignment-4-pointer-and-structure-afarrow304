#include "item.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//adds items to an existing array
void add_item(Item *item_list, double price, char *sku, char *category,char *name, int index){
	item_list[index].price = price;
	item_list[index].sku =strdup(sku);
	item_list[index].category =strdup(category);
	item_list[index].name = strdup(name);

}
void free_items(Item *item_list, int size){
	int i;
	for(i=0;i<size;i++){
		free(item_list[i].sku);
		free (item_list[i].name);
		free (item_list->category);
	}
	free(item_list);
}
double average_price(Item *item_list, int size){
	int i;
	double sum =0.0;
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
		printf("item name = %s\n",item_list[i].name);
		printf("item sku = %s\n",item_list[i].sku);
		printf("item category = %s\n",item_list[i].category);
		printf("item price = %.2f\n",item_list[i].price);
		printf("################\n");
	}
}
int main(int argc, char *argv[]){
	char *sku_userIn = argv[1];
	int size=5;
	Item *item_list = (Item *)malloc(size * sizeof(Item));
	//adding 5 diffrent items
	add_item(item_list, 6.70,(char*)"58930",(char*)"grain",(char*)"flour",0);	
	add_item(item_list, 5.00,(char*)"02357",(char*)"Dairy",(char*)"iceCream",1);
	add_item(item_list, 0.50,(char*)"50994",(char*)"Fruit",(char*)"apple",2);
	add_item(item_list, 3.25,(char*)"37495",(char*)"grain",(char*)"rice",3);
	add_item(item_list, 2.50,(char*)"97638",(char*)"Dairy",(char*)"milk",4);
	//find item using given SKU
	//using a while loop and print the item to the screen.
	//If not found, print item not found
	bool found=false;
	int i=0;
	while(!found &&  i<size){
		if(strcmp(item_list[i].sku, sku_userIn) == 0){
			printf("Item Found\n");
			printf("###############\n");
			printf("item found name = %s\n", item_list[i].name);
			printf("item found sku = %s\n", item_list[i].sku);
			printf("item found category = %s\n", item_list[i].category);
			printf("item found price = %.2f\n", item_list[i].price);
			printf("###############\n");
			found = true;
			break;
		}
		i++;
	}
	if(!found){
		printf("Item not found");
	}
	print_items(item_list, size);
	printf("average price of items = %.2f\n",average_price(item_list, size));
	free_items(item_list, size);
	return 0;
}
