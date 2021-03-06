/*
** COPYRIGHT mandeep singh 2017 under
                    GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007

*/


#include "declaration.h"

void deleteFile(char file_name[]){
    char *name = (char*)malloc(sizeof(char) * (2*MAX_NAME + 15));
    strcpy(name, "rm -rf ");
    strcat(name, "./FILES/");
    strcat(name, file_name);
    system(name);
    free(name);
    printf("%s deleted successfully\n",file_name);
}

void print_file_contents(FILE *fp){
    int c;
    while ((c = getc(fp)) != EOF){
        putchar(c);
    }
}

FILE * open_file(char file_name[] , char perm[]){
    FILE *fp;
    struct stat st = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char *name = (char *)malloc(sizeof(char) * (2 * MAX_NAME + 15));
       strcpy(name, "./FILES/");

    if (stat(name, &st) == -1)
        mkdir(name, 0775);

    strcat(name, file_name);
    // cout<<"name:: "<<name<<endl;
    // cout<<"perm:: "<<perm<<endl;
    fp = fopen(name, perm);
    // cout<<"fp: "<<fp<<endl;
    if (!fp){
        printf("\nError in opening file\n");
        exit(0);
    }
    free(name);
    return fp;
}

void delete_file(char file_name[]){
    //FILE *fp;
    //struct stat st = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char *name = (char *)malloc(sizeof(char) * (2 * MAX_NAME + 15));
    strcpy(name,"rm -rf ");
    strcat(name, "./FILES/");
    strcat(name, file_name);
    system(name);
    free(name);
}

int check_file_existence(char file_name[]){
    /*
    FILE *fp;
    struct stat st = {0};
    char *name = (char*)malloc(sizeof(char)*(2*MAX_NAME));
    strcpy(name,"./FILES");
    if(stat(name,&st)== -1)
        mkdir(name,0775);
    strcat(name,file_name);
    fp = fopen(name,perm);
    if(!fp){
        return 0;
    }
    else return 1;
    return 0;
    */
    /*
    if(access(file_name, F_OK)!=-1){
        return 1;
    }
    else return 0;
    */
    struct stat   buffer;
    //printf("stat : %d\n",stat (file_name, &buffer));
    return (stat (file_name, &buffer) == 0);
}
