https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#

*******************************************SOLUTION**********************************88
  
  
 string reverse(string result)
    {
        int start = 0;
        int end = result.length() - 1;
        while(start < end)
        {
            char ch = result[start];
            result[start] = result[end];
            result[end] = ch;
            start++;
            end--;
        }
        return result;
    }

    string solve(int arr[], int n) 
    {
        // code here
        sort(arr, arr + n);
        string num1;
        string num2;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                num1+=to_string(arr[i]);
            else
                num2+=to_string(arr[i]);
        }
        //check the string length
        string temp;
        if(num1.length() > num2.length())
        {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        
        int index = num1.length() - 1;
        int carry = 0;
        int sum = 0;
        //string temp;
        string result;
        //cout<<num1<<" "<<num2<<"\n";
        int p=0;
        while(index >= 0)
        {
            int val1 = (num1[index]) - '0';
            
            int val2 = (num2[num2.length()-1-p]) - '0';
            //cout<<val1<<" "<<val2<<"\n";
            sum = val1 + val2 + carry;
            //cout<<sum<<"\n";
            if(sum > 9)
            {
               carry = sum / 10;
               sum = sum % 10;
            }
            else
            {
                carry = 0;
                
            }
            result+=to_string(sum);
            sum = 0;
            index--;
            ++p;
        }
        int curr_index = num2.length() - num1.length() - 1;
        while(curr_index >= 0)
        {
            int val1 = (num2[curr_index]) - '0';
            
            sum = val1 + carry;
            if(sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
               
            }
            else
            {
                carry = 0;
            }
            result+=to_string(sum);
            sum = 0;
            curr_index--;
        }
        //reversing the result
        //result = reverse(result);
        if(carry != 0)
            result+=to_string(carry);
        string per_result;
        bool flag = false;
        for(int i = result.length()-1; i >=0; i--)
        {
            if(result[i] != '0')
            {
                //first non zero digit
                per_result+=result[i];
                flag = true;
            }
            else
            {
                if(flag == true)
                    per_result+=result[i];                   
                
            }
            
            //cout<<per_result<<"\n";
        }
        
        return per_result;
    }
