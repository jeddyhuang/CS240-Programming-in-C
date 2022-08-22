typedef struct Student {
	int grade; 
	char *name;
	struct Student *next;
} Student_Record;

int deallocate_list(Student_Record *);