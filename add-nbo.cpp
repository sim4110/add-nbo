#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<arpa/inet.h>

uint32_t read_file(char*filename){
    FILE*fp = fopen(filename, "rb");
    uint32_t num;

    if(fp == NULL){
        exit(1);
    }

    fread(&num, sizeof(uint32_t), 1, fp);

    fclose(fp);
    return ntohl(num);
}

int main(int argc, char*argv[]){

    char*file1 = argv[1];
    char*file2 = argv[2];
    
    uint32_t n1 = read_file(file1);
    uint32_t n2 = read_file(file2);

    uint32_t result = n1 + n2;

    printf("%u(%#x) + %u(%#x) = %u(%#x) ", n1,n1,n2,n2,result,result);

    return 0;
}