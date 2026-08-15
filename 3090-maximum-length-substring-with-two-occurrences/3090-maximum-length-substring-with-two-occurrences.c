int maximumLengthSubstring(char* s){
    int freq[26] = {0};
    int left = 0;
    int maxLength = 0;
    for(int right = 0; s[right] != '\0'; right++){
        freq[s[right] - 'a']++;
        while(freq[s[right] - 'a'] > 2){
            freq[s[left] - 'a']--;
            left++;
        }
        int currentLength = right - left + 1;
        if(currentLength > maxLength){
            maxLength = currentLength;
        }
    }
    return maxLength;
}