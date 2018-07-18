#include "schooldaoimpl.h"

#define TEACHER_TABLE "TEACHER_TABLE"
#define STUDENT_TABLE "STUDENT_TABLE"

#define CREATE_TEACHER_CMD "CREATE TABLE "+TEACHER_TABLE+"(\
NUM INT PRIMARY KEY,   \
NAME TEXT NOT NULL,\
SEX BOOLEAN NOT NULL,\
)"

#define CREATE_STUDENT_TABLE_CMD "create table "+STUDENT_TABLE+"(\
id int primary key,   \
name text not null,\
score real not null)"


SchoolDaoImpl::SchoolDaoImpl()
{
}
