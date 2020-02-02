#include<iostream>
using namespace std;
int mat[10][6];

void swap(int *a,int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void sort(int num ,int mat[][6])
{
  for(int i = 0;i<num;i++){
    for(int j=0;j<num;j++){
      if(mat[j][1] > mat[j+1][1])
      {
        for(int k=0;k<5;k++){
          swap(mat[j][k],mat[j+1][k]);
        }
      }
    }
  }
}
void Endtime(int num, int mat [][6])
{
  int temp,val;
  mat[0][3] = mat[0][1] + mat[0][2];
  mat[0][5] = mat[0][3] - mat[0][1];
  mat[0][4] = mat[0][5] - mat[0][2];

  for(int i=1;i<num;i++)
  {
    temp=mat[i-1][3];
    int low = mat[i][2];
    for(int j=i;j<num;j++)
    {
      if(temp >=mat[j][1] && low >= mat[j][2])
      {
        low = mat[j][2];
        val=j;
      }
    }
    mat[val][3] = temp + mat[val][2];
    mat[val][5] = mat[val][3] - mat[val][1];
    mat[val][4] = mat[val][5] - mat[val][2];
    for(int k=0; k<6 ;k++){
      swap(mat[val][k],mat[i][k]);
    }
  }
}

int main()
{
  int num, temp;
  cout<<"enter the number of processes";
  cin>>num;
  cout<<"Enter Id..\n";
  cin>>num;
  for(int i=0;i<num;i++){
    cout<<"process"<<i+1<<"\n";
    cin>>mat[i][0];
    cout<<"Enter the arrival time";
    cin>>mat[i][1];
    cout<<"Enter the Burst time";
    cin>>mat[i][2];
  }

  std::cout << "before arrange" << '\n';
  cout<<"Process ID\tArrival Time\tBurst Time\n";
  for(int i=0; i<num; i++){
    cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2];
  }
  sort(num,mat);
  Endtime(num,mat);
  std::cout << "Final Result" << '\n';
  std::cout << "Id\tArrival Time\tBurst Time\t waiting Time\t Turnaround Time" << '\n';
  for (size_t i = 1; i < num; i++) {
    /* code */
    cout<<mat[i][0]<<"\t\t"<<mat[i][1]<<"\t\t"<<mat[i][2]<<"\t\t"<<mat[i][3]<<"\t\t"<<mat[i][4]<<"\t\t"<<mat[i][5]<<"\n";
  }
}
