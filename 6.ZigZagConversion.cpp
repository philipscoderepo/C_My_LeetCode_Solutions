class Solution {
public:
    string convert(string s, int numRows) {
        //Middle = numRows - 2
        //Shift = numRows + middle
        //Top and Bottom increments over shift since there are no middle elements
        //Middle elements are at pos = numRows - current_row + middle + col_shift

        string str;
        //Current_row is index
        int current_row = 0,
            middle = numRows-2,
            shift = numRows+middle;

        while(current_row < numRows){
            //Get the top or bottom
            if(current_row==0 || current_row==numRows-1){
                int index = current_row;
                while(index < s.length()){
                    str += s[index];
                    index += shift;
                }
            }
            else{
                int index = current_row,
                col_shift = 0;

                while(index < s.length()){
                    str += s[index];
                    //Make sure there is still data to be read after the column shift
                    if(numRows-current_row+middle+col_shift < s.length()){
                        str += s[numRows-current_row+middle+col_shift];
                    }
                    index += shift;
                    col_shift += shift;
                }
            }

            current_row++;
        }

        return str;
    }
};
