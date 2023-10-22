#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct student {
	char name[2];//姓名
	int num;//学号
	char exe[1];//性别
	int  MAscore;//数学成绩
	int PHscore;//物理成绩
	int  EDscore;//工程制图成绩
	int ELC1score;//英语成绩
	int  CPscore;//C语言成绩
	double weight;//加权成绩
	double average;//平均成绩
}stu[2];
int cmp(const void *a,const void *b){
   
    return ((student*)b)->weight-((student*)a)->weight;
 }
int main() {
	printf("**************************************************************\n");
	printf("*\t欢迎使用学生期末成绩统计系统\t*\n");
	printf("**************************************************************\n");
	printf("*\t小组成员：\t*\n");
	printf("*\t\t1.录入学生信息\t\t\t\t*\n");
	printf("*\t\t2.读取学生信息\t\t\t\t*\n");
	printf("*\t\t3.设置各科目计算权重\t\t\t*\n");
	printf("*\t\t4.学生加权成绩\t\t\t\t*\n");
	printf("*\t\t5.学生各科成绩、平均成绩及加权成绩\t*\n");
	printf("*\t\t6.学生加权成绩排序\t\t\t*\n");
	printf("*\t\t7.保存成绩\t\t\t\t*\n");
	printf("*\t\t8.结束界面\t\t\t\t*\n");
	printf("**************************************************************\n");
	printf("请输入学生 姓名 学号 性别 数学成绩 物理成绩 工程制图成绩 英语成绩 C语言成绩  \n");
	struct student* p;
	p = stu;
	int a;
	for (a = 0; a < 5; a++)
		scanf("%s%d%s%d%d%d%d%d", stu[a].name, &stu[a].num, stu[a].exe, &stu[a].MAscore, &stu[a].PHscore, &stu[a].EDscore, &stu[a].ELC1score, &stu[a].CPscore);
	for (a = 0; a < 5; a++)
		stu[a].weight = stu[a].MAscore * 0.25 + stu[a].PHscore * 0.25 + stu[a].EDscore * 0.125 + stu[a].ELC1score * 0.25 + stu[a].CPscore * 0.125;
	for (a = 0; a < 5; a++)
		stu[a].average = (stu[a].MAscore + stu[a].PHscore + stu[a].EDscore + stu[a].ELC1score + stu[a].CPscore) * 0.2;
        qsort(stu,5,sizeof(stu[0]),cmp);
	printf("\n************************************学生************************************\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("| Name | num |   exe   |  数学  |  物理  | 工程制图 |  英语  |   C语言  | \n");
	for (a = 0; a < 5; a++)
		printf("| %s |  %d   |   %s    |  %d     |  %2d  |   %2d    |  %2d   |       %d |  \n", stu[a].name, stu[a].num, stu[a].exe, stu[a].MAscore, stu[a].PHscore, stu[a].EDscore, stu[a].ELC1score, stu[a].CPscore);
	for (a = 0; a < 5; a++)
		printf("加权成绩：%f\n", stu[a].weight);
	for (a = 0; a < 5; a++)
		printf("平均成绩：%f\n", stu[a].average);
	printf("-------------------------------------------------------------------------------\n");
		return 0;
}
