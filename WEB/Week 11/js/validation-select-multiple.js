/* validation-select-multiple.js */
       function checkForm() {

               var NoOfOptions = document.example.whatToDo.options.length;
               var messages="<p>No. of select wish list options = <mark>" + NoOfOptions + "</mark></p>";
               var result="";
               //alert(document.example.whatToDo.selectedIndex);
               /* The selectedIndex property sets or returns the index of the selected option in a drop-down list.
                    The index starts at 0.
                    If the drop-down list allows multiple selections it will only return the index of the first option selected.
                    The value "-1" will deselect all options (if any).
                    If no option is selected, the selectedIndex property will return -1.
               */
               /* var sIndex = document.example.whatToDo.selectedIndex; 
               if (sIndex == -1) {                                        
                    result="";
               } else {
                    result += "<p>You have selected <mark>";
                    result += document.example.whatToDo[sIndex].text + "</mark> with a value of <mark>";
                    result += document.example.whatToDo[sIndex].value + "</mark></p>";    
               } */
              
               for (var i = 0; i < NoOfOptions; i++) {

                 //if (document.example.whatToDo[i].selected==true) {
                   if (document.example.whatToDo[i].selected) {
                    result += "<p>You have selected <mark>";
                    result += document.example.whatToDo[i].text + "</mark> with a value of <mark>";
                    result += document.example.whatToDo[i].value + "</mark></p>";
                 } // end of if
               } // End of for


               if (result=="") { 
                    messages += "<p>None selected</p>"; 
                    showErrors(messages); 
                    return false; // return false - allow for changes - form not submitted
               }
               else { 
                   // messages += "<p>You have selected - <mark>" + result + "</p>";
                   messages += result;
                    showErrors(messages); 
                    //return false;        
                    return true;  

               }

    } // End of function


     function showErrors(messages) {
        
         document.querySelector('#errors').innerHTML = messages;

     }  //  End of function


     // ****************************************************************
     // ** Function Name : clearShowErrors()                          **
     // **                                                            **
     // ** Called from   : the html file                              **
     // ****************************************************************
     // ** Function Description                                       **
     // ** ====================                                       **
     // **                                                            **
     // ** This function is called if the clear button is clicked on  **
     // **                                                            **
     // ****************************************************************

 
     function  clearShowErrors() {

        document.querySelector('#errors').innerHTML = " ";      
     }  //  End of function