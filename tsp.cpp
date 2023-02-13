#include <iostream>
 
using namespace std;
 
/* using the const value since no cosnt can't answer value outside of fucntion*/
const int n = 3;

const int MAX = 1000000; /* The valeu to sotre the answer, sicne no buffer, the reuslt won't show up wuthout out a buffer*/
 
const int value = n + 1;
/* the matrix used to find the tsp */
int Tsp_Matrix[value][value] = {
    { 0, 0, 0, 0},    { 0, 0, 10, 15},
    { 0, 10, 0, 25 }, { 0, 15, 25, 0 },

};
 
/* The array used for dynamic algorimns and is used to store the vlaeu for te i and j value so we don't have to calulate this more. */
int Tsp_Array[value][1 << (value)];

/* The function that finds the most effcient path in a matrix, used i sicne the  << is used to counts bits and if i is not in it won't work as the other varaible name has different bit number affecting the result*/
int Tsp_Finder(int i, int combination)
{
  /* As showed by the recurren realtion when the combination and the i vale is  in the bit for 1 then return the valeu since we went to every node */
    if (combination == ((1 << i) | 3))
        return Tsp_Matrix[1][i];

  /* Record any new combiantion taht hasn't occur yet in the array for further use */
    if (Tsp_Array[i][combination] != 0)
        return Tsp_Array[i][combination];

  /* The varible taht stores the array, amke the storage size big so the valeu can fix since if it done't fit the value will ahve nothing nside */
    int result = MAX; 


    /* The loop that go through each of the node to find the best soltuion by find thie min of each the value now of ij and the rpevious i j value stored in the array */
    for (int j = 1; j <= n; j++)
        if ((combination & (1 << j)) && j != i && j != 1)
            result = std::min(result, Tsp_Finder(j, combination & (~(1 << i)))
                                    + Tsp_Matrix[j][i]);
    return Tsp_Array[i][combination] = result; 
}

int TSP_answer(int ans){/* This is a helper fucntiont aht is used to display the tsp array */

    for (int i = 1; i <= n; i++)
      /* Thi is used to find the aculally tsp best path as the tsp Finder find it for that node to every other node and this acually finds it  */
        ans = std::min(ans, Tsp_Finder(i, (1 << (n + 1)) - 1)
                                + Tsp_Matrix[i][1]);


    return ans;
 
}
int main()
{
    int ans = MAX;


    ans = TSP_answer(ans);
 

    cout << "The least weight path for this matrix is : " << ans <<endl;
    return 0;
}
