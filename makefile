out: student.o stud_add.o search.o stud_save.o stud_del.o stud_show.o stud_mod.o stud_sort.o
	cc student.c stud_add.c search.c stud_save.c stud_del.c stud_show.c stud_mod.c stud_sort.c -o out

student.o: student.c
	cc -c student.c
stud_add.o: stud_add.c
	cc -c stud_add.c
search.o: search.c
	cc -c search.c
stud_save.o: stud_save.c
	cc -c stud_save.c
stud_del.o: stud_del.c
	cc -c stud_del.c
stud_show.o: stud_show.c
	cc -c stud_show.c
stud_mod.o: stud_mod.c
	cc -c stud_mod.c
stud_sort.o: stud_sort.c
	cc -c stud_sort.c
