#include <stdio.h>
#include <stdlib.h>
#include "deallocate_list.h"

int deallocate_list(Student_Record * list){
    if(list == NULL) return -1;
    deallocate_list(list->next);
    free(list->name);
    free(list);
    return 0;
}