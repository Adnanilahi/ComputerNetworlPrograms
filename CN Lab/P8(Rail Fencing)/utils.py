def enkrypt(s,k):
    n = len(s)
    ans = ""
    for i in range (0,k,1):
        j = i
        if i==0:
            while j<n:
                if(j<n):
                    ans = ans+s[j]
                j = (j+(k-i-1)*2)

        if i == k-1:
            while j<n:
                if j<n:
                    ans = ans+s[j]
                j = j + (i*2)
        if j<n:
            ans = ans + s[j]
        
        while j<n:
            j = j + ((k-i-1)*2)
            if j<n:
                ans = ans+s[j]
            
            j = j + (i*2)
            if j<n:
                ans = ans + s[j]
    
    return ans

def decrypt(s, k):
 
    
    rail = [['\n' for i in range(len(s))]
                  for j in range(k)]
     
    dir_down = None
    row, col = 0, 0
     
    for i in range(len(s)):
        if row == 0:
            dir_down = True
        if row == k - 1:
            dir_down = False
         
        rail[row][col] = '*'
        col += 1
         
        
        if dir_down:
            row += 1
        else:
            row -= 1
             
    
    index = 0
    for i in range(k):
        for j in range(len(s)):
            if ((rail[i][j] == '*') and
               (index < len(s))):
                rail[i][j] = s[index]
                index += 1
         
  
    result = []
    row, col = 0, 0
    for i in range(len(s)):
         
        if row == 0:
            dir_down = True
        if row == k-1:
            dir_down = False
             
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
             
       
        if dir_down:
            row += 1
        else:
            row -= 1
    return("".join(result))
 
