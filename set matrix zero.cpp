void booleanMatrix(vector<vector<int> > &a)
   {
     int n=a.size(),m=ua[0].size();
      bool row=false,col=false;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0&&a[i][j]==1)
                   row=true;
               if(j==0&&a[i][j]==1)
                   col=true;
               if(a[i][j]==1)
               {
                   a[i][0]=1;
                   a[0][j]=1;
               }
           }
       }
       for(int i=1;i<n;i++)
       {
           for(int j=1;j<m;j++)
           {
               if(a[0][j]==1||a[i][0]==1)
               {
                   a[i][j]=1;
               }
           }
       }
       if(row==true)

       {
       for(int j=0;j<m;j++)
       {
          a[0][j]=1;
       }
       }
       if(col==true)
       {
           for(int i=0;i<n;i++)
       {
          a[i][0]=1;
       }

       }
       
