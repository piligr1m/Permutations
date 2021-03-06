//
//  main.cpp
//  Permutations
//
//  Created by Stanislav Martynov on 30.12.2020.
//

#include <iostream>
#include <vector>

void Sort(int *arr, int n)
{
   int min, temp;
   int temp1 = 0;
  for (int i = 0; i < n - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
    temp1++;
  }
}

void swap(int *a, int i, int j)
{
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}

bool generate_perm(int *a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false;
  int k = n - 1;
  while (a[j] >= a[k]) k--;
  swap(a, j, k);
  int l = j + 1, r = n - 1;
  while (l<r)
    swap(a, l++, r--);
  return true;
}
void Print(int *a, int n)
{
  for (int i = 0; i < n; i++)
    std::cout << a[i] << " ";
  std::cout << std::endl;
}
bool array_comp(int *a, int *b, int k){
    for (int i = 0; i < k; i++){
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main()
{
    std::vector<int> vec1;
    std::string line;
    int current = 0;
    int sign = 1;
    int k = 0;
    int j = 0;
    bool flag = false;
    std::getline(std::cin, line);
    vec1.resize(line.size());
    for (int i = 0; i < line.size(); i++){
        if(std::isdigit(line[i]))
        {
            current = current*10 + (line[i]-48);
            flag = true;
        }
        else if (line[i] == '-'){
            if (current == 0) sign = -1;
        }
        if ((!std::isdigit(line[i]) && (current != 0 || flag)) || line[i+1] == '\0'){
            k++;
            vec1[j] = current*sign;
            j++;
            current = 0;
            sign = 1;
            flag = false;
         }
    }
    if(!line.empty()){
    int der[k];
    int sorted_arr[k];
    int der1[k];
    for (int i =0; i < k; i++) {
        der[i] = vec1[i];
        sorted_arr[i] = vec1[i];
        der1[i] = vec1[i];
    }
    vec1.clear();
    Sort(sorted_arr, k);
        Print(der, k);
        while (generate_perm(der, k)) Print(der, k);
        if (!array_comp(sorted_arr, der1, k)){
            Print(sorted_arr, k);
        while (generate_perm(sorted_arr, k)){
            if (array_comp(sorted_arr, der1, k)) break;
            Print(sorted_arr, k);
        }
        }
}
}
