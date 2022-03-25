//LAHCEN EL OUARDI

#include "algorithms.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void array_create(struct array *self) {
	self->data = NULL;
	self->size=0;
}

void array_create_from(struct array *self, const int *other, size_t size) {
if(self==NULL || other ==NULL)
	return;
self->size = size;
self->data=malloc(size * sizeof(int));
for(int i=0; i<size;i++){
	self->data[i]=other[i];
	
}

}

void array_destroy(struct array *self) {
free(self->data);
self->data=NULL;

}

bool array_empty(const struct array *self) {
if(self->size==0)
	return true;
  return false;
}

size_t array_size(const struct array *self) {
  return self->size;
}

bool array_equals(const struct array *self, const int *content, size_t size) {
  if(self == NULL || content == NULL)
  	return false;
  if(self->data == NULL || self->size != size)
  	return false;
  for(int i=0; i<size;i++){
  	if(self->data[i]!=content[i]){
  		return false;
  	}
  }
  return true;
}


void array_push_back(struct array *self, int value) {

int *tab=malloc((self->size+1)*sizeof(int));
int i=0;

for(i;i<self->size;i++){

	tab[i]=self->data[i];
}
tab[i]=value;
free(self->data);
self->data=NULL;
self->data=tab;
self->size++;
}




void array_pop_back(struct array *self) {
self->data[self->size-1]=NULL;
self->size=self->size-1;
}

void array_insert(struct array *self, int value, size_t index) {
/*

self->size++;
self->data=realloc(self->data,self->size*sizeof(int));
for (int i=self->size-1;i>index;i--){
	self->data[i]=self->data[i-1];
}
self->data[index]=value;*/

int *tab=malloc((self->size+1)*sizeof(int));

for(int i=0;i<index;i++){
	tab[i]=self->data[i];
}
tab[index]=value;
for(int j=index;j<self->size;j++){
	tab[j+1]=self->data[j];
}
free(self->data);
self->data=NULL;
self->data=tab;
self->size++;

}

void array_remove(struct array *self, size_t index) {

for(int i=index;i<self->size-1;i++){
	self->data[i]=self->data[i+1];	
}
self->data[self->size-1]=NULL;
self->size--;

}

int array_get(const struct array *self, size_t index) {
if(index<self->size){
	return self->data[index];
}
	
  return 0;
}

void array_set(struct array *self, size_t index, int value) {
if(index>=0 && index <self->size){
	self->data[index]=value;
}
return;
}

size_t array_search(const struct array *self, int value) {

	for(int i=0;i<self->size;i++){
		if(self->data[i]==value){
			return i;
		}
	}  
  return self->size;

}


size_t array_search_sorted(const struct array *self, int value) {
	size_t deb=0;
	size_t fin=self->size-1;
	size_t mid;
	if(value>self->data[fin] || value<self->data[deb])
		return self->size;
	while(deb<=fin){
		mid=(deb+fin)/2;
		if(value ==self->data[mid]){
			return mid;
		}else if (value>self->data[mid]){
			deb=mid+1;
		}else{
			fin=mid-1;
		}
		
	}

  return self->size;
}

bool array_is_sorted(const struct array *self) {
	for(int i=1;i<self->size;i++){
		if(self->data[i-1]>self->data[i]){
			return false;
		}
	}
	return true;
}
void array_swap(int *data, size_t i, size_t j) {
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

ptrdiff_t array_partition(struct array *self, ptrdiff_t i, ptrdiff_t j) {
  ptrdiff_t pivot_index = i;
  const int pivot = self->data[pivot_index];
  array_swap(self->data, pivot_index, j);
  ptrdiff_t l = i;
  for (ptrdiff_t k = i; k < j; ++k) {
  	if (self->data[k] < pivot) {
  		array_swap(self->data, k, l);
  		++l;
  	}
  }
  array_swap(self->data, l, j);
  return l;
}
void array_quick_sort_partial(struct array *self,ptrdiff_t i, ptrdiff_t j) {
	if (i < j) {
		ptrdiff_t p = array_partition(self, i, j);
		array_quick_sort_partial(self, i, p - 1);
		array_quick_sort_partial(self, p + 1, j);
	}
}

void array_quick_sort(struct array *self) {

	array_quick_sort_partial(self, 0, self->size - 1);
}



void array_heap_sort(struct array *self) {
/*
	struct array *tab=malloc(sizeof(struct array));
	array_create(tab);
	int n = self->size;
	for (size_t i = 0; i < n; ++i) {

			int value = self->data[i];

			array_heap_add(tab, value);

		}
		
		for (size_t i = 0; i < n; ++i) {

			int value = tab->data[0];

			array_heap_remove_top(tab);

			tab->data[n - i - 1] = value;

		}
		self->data = tab->data;
		free(tab);
		tab->data=NULL;
*/
}





bool array_is_heap(const struct array *self) {

	if(self!=NULL){
		int n = self->size;
		if(n>0){
			int i=0;
			while(i <= (n-1)/2){

				if(array_get(self,i) < array_get(self,2*i+1) || array_get(self,i) < array_get(self,2*i+2)){

					return false;
				} else{
					i++;
				}
			
			
			}
		}
	}

  return true;
}

void array_heap_add(struct array *self, int value) {

	size_t i = self->size;

	array_push_back(self,value);

	while (i > 0) {
	size_t j = (i - 1) / 2;
		if (self->data[i] < self->data[j]) {
			break;
			}
		array_swap(self->data, i, j);
		i = j;
		}

}

int array_heap_top(const struct array *self) {
  return array_get(self,0);
}




void array_heap_remove_top(struct array *self) {
	int n = self->size;
	if(n>1){
	self->data[0] = self->data[n-1];
	size_t i=0;
	while(i <(n-1) / 2){
		size_t lt = 2*i+1;
		size_t rt = 2*i+2;
		if(self->data[i] > self->data[lt] && self->data[i] > self->data[rt]){
			break;	
		}
		size_t j;
		if(self->data[lt]>self->data[rt]){
			j=lt;
		}else{
			j=rt;
		}
		array_swap(self->data,i,j);
		i = j;
	}
	}
	self->size--;
}



/*
 * list
 */

void list_create(struct list *self) {


	self->first = NULL;

	
}

void list_create_from(struct list *self, const int *other, size_t size) {
	if(size <=0){
		return;
	}
	struct list_node *curr = malloc(sizeof(struct list_node));
	self->first = curr;
	curr->data=other[0];
	curr->next=NULL; 

	for(int i=1;i<size;i++){ 
		struct list_node *cell = malloc(sizeof(struct list_node));
		cell->data=other[i];
		cell->next=NULL;
		curr->next = cell;
		curr = cell;
	
	}
	
	
	
	
}

void list_destroy(struct list *self) {
	
	while(self->first!=NULL){
		list_pop_front (self);
	}

	
}

bool list_empty(const struct list *self) {	
	if(self == NULL)
		return true;
	if(self->first == NULL)
		return true;
	return false;
	

}

size_t list_size(const struct list *self) {

size_t compteur=0;
if (self==NULL)
	return compteur;
if (self->first==NULL)
	return compteur;
	
struct list_node *curr =self->first;
compteur++;
while(curr->next!=NULL){
	compteur++;
	curr = curr->next; 
}

return compteur;
}

bool list_equals(const struct list *self, const int *data, size_t size) {

  	 if(list_size(self)!=size){
  	 	return false;
  	 }
  	 struct list_node *curr=self->first;
  	 for(int i=0;i<size;i++){
  	 	if(data[i]!=curr->data){
  	 		return false;
  	 	}
  	 	curr=curr->next;
  	 }

  return true;
}

void list_push_front(struct list *self, int value) {
	struct list_node *new =malloc(sizeof(struct list_node));
	new->data=value;
	new->next=NULL;
	new->next = self->first;
	self->first = new;
}

void list_pop_front(struct list *self) {
	struct list_node *curr =self->first;
	self->first=curr->next;
	free(curr);
}

void list_push_back(struct list *self, int value) {
	 struct list_node *curr =self->first;
	 if(self->first==NULL){
	 	struct list_node *new =malloc(sizeof(struct list_node));
	 	new->data=value;
	 	new->next=NULL;
	 	new->next=self->first;
	 	self->first=new;
	 	return;
	 }
	 while(curr->next!=NULL){
	 	curr=curr->next;
	 }
	 struct list_node *new =malloc(sizeof(struct list_node));
	 new->data=value;
	 new->next=NULL;
	 new->next=curr->next;
	 curr->next=new;
}

void list_pop_back(struct list *self) {
	

	if(self->first==NULL){
		return;
	}
	struct list_node *curr =self->first ;
	if(curr->next != NULL){
		while(curr->next->next!=NULL ){
		 	curr=curr->next;
		}
		struct list_node *tmp = curr->next;
		curr->next = NULL;
		free(tmp);
	} else {
		self->first = NULL;
		free(curr);	
	}

}


void list_insert(struct list *self, int value, size_t index) {
	if(index<0 || index > list_size(self)){
		return;
	}
	if(index==0){
		list_push_front(self,value);
		return;
	}
	if(index==list_size(self)){
		list_push_back(self,value);
		return;
	}
	struct list_node* curr = self->first;
	for(int i=0;i<index-1;i++){
		curr = curr->next;
	}
	struct list_node *new=malloc(sizeof(struct list_node));
	new->data=value;	
	new->next=curr->next;
	curr->next=new;
	
	
}


void list_remove(struct list *self, size_t index) {
	if(index<0 || index > list_size(self)){
		return;
	}
	if(index==0){
		list_pop_front(self);
		return;
	}
	if(index==list_size(self)){
		list_pop_back(self);
		return;
	}
	struct list_node* curr = self->first;
	for(int i=0;i<index-1;i++){
		curr = curr->next;
	}
	struct list_node *other=curr->next;
	curr->next=other->next;
	free(other);
}

int list_get(const struct list *self, size_t index) {
	 if(index<0 || list_size(self)<=index || list_size(self)==0){
	  	return 0;
	  }
	struct list_node *curr = self->first;
	for(int i=0;i<index;i++){
		curr = curr->next;
	
	}return curr->data;
}

void list_set(struct list *self, size_t index, int value) {
	if(index<0 || index >= list_size(self)){
		return;
	}
	struct list_node* curr = self->first;
	for(int i=0;i<index;i++){
		curr=curr->next;
	}
	curr->data=value;
}

size_t list_search(const struct list *self, int value) {
	struct list_node *curr =self->first;
	if(self->first ==NULL){
		return 0;
	}
	size_t i=0;
	while(curr!=NULL){
		if(curr->data==value){
			return i;
		}
	curr=curr->next;
	i++;
	}
  return i;
}

bool list_is_sorted(const struct list *self) { 

struct list_node *curr =self->first;
if(self->first==NULL){
	return true;
}
	while(curr->next!=NULL){
		if(curr->data >curr->next->data){
			return false;
		}
	curr=curr->next;
}
return true;
}

void list_split(struct list *self, struct list *out1, struct list *out2) {
int taille = list_size(self);
int index=taille/2;

for(int i=0;i<index;i++){
	list_push_back(out1,self->first->data);
	list_pop_front(self);
}
for(int i=index;i<taille;i++){
	list_push_back(out2,self->first->data);
	list_pop_front(self);
}

}

void list_merge(struct list *self, struct list *in1, struct list *in2) {

	while(in1->first!=NULL && in2->first!=NULL){
		if(in1->first->data<in2->first->data){
			list_push_back(self,in1->first->data);
			list_pop_front(in1);
		}else{
			list_push_back(self,in2->first->data);
			list_pop_front(in2);
		}
	}
	if(in1->first!=NULL){
		while(in1->first!=NULL){
			list_push_back(self,in1->first->data);
			list_pop_front(in1);
		}
	}else if(in2->first!=NULL){
		while(in2->first!=NULL){
			list_push_back(self,in2->first->data);
			list_pop_front(in2);
		}
	
	}

}

void list_merge_sort(struct list *self) {
if(list_size(self)>1){

	struct list *in1=malloc(sizeof(struct list));
	struct list *in2=malloc(sizeof(struct list));
	in1->first=NULL;
	in2->first=NULL;
	list_split(self,in1,in2);
	list_merge_sort(in1);
	list_merge_sort(in2);
	list_merge(self,in1,in2);
	free(in1);
	free(in2);

}

}


/*
 * tree
 */

void tree_create(struct tree *self) {
	self->root=NULL;


}


void tree_destroy(struct tree *self) {
	if(self->root==NULL){
		return;
	}
	struct tree t1_tmp;
  	t1_tmp.root = self->root->left;
  	struct tree t2_tmp;
  	t2_tmp.root = self->root->right;
	tree_destroy(&t1_tmp);
	tree_destroy(&t2_tmp);
	free(self->root);
}

bool tree_contains(const struct tree *self, int value) {
	if(self->root==NULL){
		return false;
	}
	if(self->root->data==value){
		return true;
	}
	struct tree t1_tmp;
  	t1_tmp.root = self->root->left;
  	struct tree t2_tmp;
  	t2_tmp.root = self->root->right;
  	return tree_contains(&t1_tmp,value) || tree_contains(&t2_tmp,value);

	
	
}

bool tree_insert(struct tree *self, int value) {
	if(tree_contains(self,value)){
		return false;
	}
	struct tree_node *new=malloc(sizeof( struct tree_node));
	new->data=value;
	new->left=NULL;
	new->right=NULL;
	if(self->root==NULL){

		self->root=new;
		return true;
	}
	struct tree_node *tree_tmp = self->root;
	struct tree_node *tree_tmp_root;
	while(tree_tmp != NULL){
		tree_tmp_root = tree_tmp;
		if(tree_tmp->data > value){
			tree_tmp = tree_tmp->left;
		} else{
			tree_tmp = tree_tmp->right;
		}
	}
	
	if(tree_tmp_root->data > value){
		tree_tmp_root->left = new;
	} else{
		tree_tmp_root->right = new;
	}
	return true;

}
int min(struct tree_node *self){
	int min=self->data;
	while(self->left!=NULL){
		self = self->left;
		min = self->data;
	}
	return min;
	
}

bool tree_remove(struct tree *self, int value) {
	if(!tree_contains(self,value)){
		return false;
	}
	if(self->root!=NULL){
		if(self->root->left==NULL && self->root->right==NULL){
			if(self->root->data==value){
				free(self->root);
				self->root=NULL;
				return true;
			}
			return false;
			
		}
		struct tree_node *tree_tmp = self->root;
		struct tree_node *tree_tmp_root = self->root;
		
		while(tree_tmp->data != value){
			tree_tmp_root = tree_tmp;
			if (tree_tmp->data > value){
				tree_tmp = tree_tmp->left;
			} else {
				tree_tmp = tree_tmp->right;
			}
		}
		if(tree_tmp->left == NULL && tree_tmp->right == NULL){
			if(tree_tmp_root->left!=NULL){
				if(tree_tmp_root->left->data == tree_tmp->data){

					tree_tmp_root->left = NULL;
				}
			}
			if(tree_tmp_root->right!=NULL){
				if(tree_tmp_root->right->data == tree_tmp->data){
					
					tree_tmp_root->right = NULL;
				}
			}
			
			free(tree_tmp);
			tree_tmp=NULL;
		} else if (tree_tmp->right == NULL){
			struct tree_node * tree_rm;
			tree_rm = tree_tmp->left;
			tree_tmp->data = tree_rm->data;
			tree_tmp->left = tree_rm->left;
			tree_tmp->right = tree_rm->right;
			free(tree_rm);
			tree_rm=NULL;
		} else if(tree_tmp->left == NULL){
			struct tree_node * tree_rm;
			tree_rm = tree_tmp->right;
			tree_tmp->data = tree_rm->data;
			tree_tmp->right = tree_rm->right;
			tree_tmp->left = tree_rm->left;
			free(tree_rm);
			tree_rm=NULL;
		} else {
			int min_sd = min(tree_tmp->right);
			tree_remove(self,min_sd);
			tree_tmp->data=min_sd;
		}
		
	
	}
	
  
  return true;
}

bool tree_empty(const struct tree *self) {
 	return (self->root==NULL);
 

}


size_t tree_size(const struct tree *self) {
  if(self->root!=NULL){
  	struct tree t1_tmp;
  	t1_tmp.root = self->root->left;
  	struct tree t2_tmp;
  	t2_tmp.root = self->root->right;
  	return 1+tree_size(&t1_tmp)+tree_size(&t2_tmp);
  	
  }else{
  	return 0;
  }

}

size_t max(size_t t1, size_t t2){
	if(t1<t2){
		return t2;
	}
	return t1;


}

size_t tree_height(const struct tree *self) {
    if(self->root!=NULL){
  	struct tree t1_tmp;
  	t1_tmp.root = self->root->left;
  	struct tree t2_tmp;
  	t2_tmp.root = self->root->right;
  	return 1+max(tree_height(&t1_tmp),tree_height(&t2_tmp));
  	
  }else{
  	return 0;
  }

}


void tree_walk_pre_order(const struct tree *self, tree_func_t func, void *user_data)  {
	
	
	if(self!=NULL){
		if(self->root!=NULL){
			func(self->root->data,user_data);
			if(self->root->left!=NULL){
				struct tree *left=malloc(sizeof(struct tree));
				left->root=self->root->left;
				tree_walk_pre_order(left,func,user_data);
				free(left);
				left=NULL;
			}
			if(self->root->right!=NULL){
				struct tree *right=malloc(sizeof(struct tree));
				right->root=self->root->right;
				tree_walk_pre_order(right,func,user_data);
				free(right);
				right=NULL;
			}
			
		
		}
	}
	
	

}

void tree_walk_in_order(const struct tree *self, tree_func_t func, void *user_data) {
	if(self!=NULL){
		if(self->root!=NULL){
			if(self->root->left!=NULL){
				struct tree *left=malloc(sizeof(struct tree));
				left->root=self->root->left;
				tree_walk_in_order(left,func,user_data);
				free(left);
				left=NULL;
			}
			func(self->root->data,user_data);
			if(self->root->right!=NULL){
				struct tree *right=malloc(sizeof(struct tree));
				right->root=self->root->right;
				tree_walk_in_order(right,func,user_data);
				free(right);
				right=NULL;
			}
		}
	}


}

void tree_walk_post_order(const struct tree *self, tree_func_t func, void *user_data) {
if(self!=NULL){
		if(self->root!=NULL){
			if(self->root->left!=NULL){
				struct tree *left=malloc(sizeof(struct tree));
				left->root=self->root->left;
				tree_walk_post_order(left,func,user_data);
				free(left);
				left=NULL;
			}

			if(self->root->right!=NULL){
				struct tree *right=malloc(sizeof(struct tree));
				right->root=self->root->right;
				tree_walk_post_order(right,func,user_data);
				free(right);
				right=NULL;
			}
			func(self->root->data,user_data);
		}
	}


}
