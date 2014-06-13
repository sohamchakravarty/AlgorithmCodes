/*
Definition: Given a string S, Zi(S) = length of the longest	substring in S starting at the ith position that matches a prefix of S.
1. Compute Z2.
2. - k>r...manual computation
   - k<r...
		1.  Zk' < |B| (we know k and r,B = r-k,A = Z(k-1), B is a subset of A)
			Zk = Zk' (no explicit comparisons)
		2.	Zk' > |B|
			Zk = |B| (no explicit comparisons)
		3.	Zk' = |B|
			Zk = |B| + explicit comparisons
*/

long compute_z(char str[]){
   long sum=0;
   int n = strlen(str);
   int z[n];
 
   sum = z[0] = n;
   long L = 0, R = 0;
   for (long i = 1; i < n; i++) {
      if (i > R) {
         L = R = i;
         while (R < n && str[R-L] == str[R]) R++;
         z[i] = R-L; R--;
      }
 
      else {
 
         int k = i-L;
         if (z[k] < R-i) z[i] = z[k];  //B = R-i
         else {
            L = i;
            while (R < n && str[R-L] == str[R]) R++;
            z[i] = R-L; R--;
         }
      }
      sum+=z[i];
   }
   return sum;
}