#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct term{
    char term[200];
    double weight;
} term;

void read_in_terms(term **terms, int *pnterm, char *filename)
{
    FILE *fp; char ch; int nterm = 0; //am I allowed to do this? I want to change the value since nterm is defined but not declared. 
    fp = fopen(filename, "r"); // since we made the pointer, and there is no textfile called "filename" we're addressing, we just put filename in directly. 
    char line[200]; //a temporary buffer I might need??? Ask about this?

    if (fp == NULL){
        printf("Unable to Open this File");
        exit(EXIT_FAILURE);} // not sure I will be allowed to do this in void. 
    // this part is a bit more random... it's so we know the file is being opened.
    else { // right now, i'm doing it character by character.... is there a more efficient way to do this?
        while (fgets(line, sizeof(line), fp)){//((ch = fgetc(fp))!= EOF){ //it's fgetc not fgets... also this is inpractical approach, reading by character. 
            printf("%c", ch);
            if (ch == '\n')
            {
                nterm ++;}}//yayy ok i get the number of terms.. although i'm sure there is a more efficient way to do this. 
            printf("\n%d", nterm);}
            *pnterm = nterm; //but this is already in the call... i feel like I'm doing this wrong. 
//you need to allocate and put them into the memory. the opening of the files is already done for you. 
//I think the storing of the numbers is already being done, do correct me if I'm wrong. 

    *terms = (term *)malloc(*pnterm*sizeof(term)); //I'm assuming this dereferences the pointer from above. This is storing the block in *terms... a pointer, like how we were asked 
    
    rewind(fp);
    //NOT SURE if this is a good appraoch but i think it is AN approach
    for (int i = 0; i < nterm; i++) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%199s %lf", (*terms)[i].term, &(*terms)[i].weight);
    }
    fclose(fp);
}
int binary_search_left(int L[],int target, int size)
{
    int left = 0;
    int right = (size - 1);
    while (left <= right){
        int mid = (left + right) /2;
        if(L[mid] < target){
            left = mid + 1;}
        else{
            right = mid - 1;}}
    return left;
}

int binary_search_right(int L[],int target, int size)
{
    int left = 0;
    int right = (size - 1);
    while (left <= right){
        int mid = (left + right) /2;
        if(L[mid] <= target){
            left = mid + 1;}
        else{
            right = mid - 1;}}
    return right;}
// you need the indices from before... adding the star also in a way makes it into a global variable
int* binary_search_deluxe(int L[], int target, int size, int *indices) //I need this to return an array, so I need to use the pointer logic like how for integers it's going to return an integer. 
{ //you already defined it in main and when calling so you don't have to do it again...
    indices[0] = binary_search_left(L, target, size);
    indices[1] = binary_search_right(L, target, size);
    return indices; }
    
int lowest_match(term *terms, int nterm, char *substr)
{

}


int main()
{

    //PART 0: Opening the Files

    //PART 1:
    term *terms;
    int nterms;
    //int nterms; // this is the number of terms.. going to take in the address of it. 
    //printf("The number of terms are %d\n",nterms); //not sure this is correct execution. 
    read_in_terms(&terms, &nterms, "wiktionary.txt"); //does this make sense?
    free(terms); // you must ALWAYS free your malloc blocks. 
    //Q: Where do you free your malloc blocks?? Can it be anywhere?
    return 0;
}