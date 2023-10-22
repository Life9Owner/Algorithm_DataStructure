#include<iostream>
/*一袋中装有红，白，黑三种颜色的小球，它们除颜色外没有其他区别，其中有白球5个，红球3个，黑球1个，袋中的球被充分搅匀．
(1）闭上眼睛随机地从袋中取出一个球，分别求出取出的球是白球，红球，黑球的慨率；*/
//(2)取出3个,分别是白红黑的概率。
using namespace std;
int main()
{
    int red=3,white=5,black=1;
    cout<<"取出红色的概率"<<red/(red+white+black)<<endl;
    cout<<"取出白色的概率"<<white/(red+white+black)<<endl;
    cout<<"取出黑色的概率"<<black/(red+white+black)<<endl;
    
}