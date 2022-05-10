let typeBox = false;
function isNumber(input) {
    var bool = false
    for (let i = -1; i < 16; i++) {
        if (!isNaN(parseInt(input[i -1]))) {
            bool = true;
        }
    }
    return bool;
}
function isEnoughL(input){
    var bool = false;
    if (input.length >= 7 && input.length <= 15) {
        bool = true;
    }
    else
    {
        bool = false;
    }
    return bool;
}  
function Validate() {
    var input = document.getElementById("passWrd").value;
    let msg = document.getElementById("request");
    var goodPassWrd             = "Good Password!";
    var number_warn             = "Require password must have a number.";
    var length_warn             = "Require password must be within 8-16 characters.";
    var LowercaseUppercase_warn = "Require password must have one character to be upper or lower case.";
    var space = "<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"
    msg.innerHTML ="<span>*</span>";
    let state = true;

    if (input.toLowerCase() == input || input.toUpperCase() == input) {
        msg.innerHTML += LowercaseUppercase_warn + space;
        state = false;
    }
    if (input.length < 8 || input.length > 16) {
        msg.innerHTML += length_warn + space;
        state = false;
    }
    if (!isNumber(input)) {
        msg.innerHTML += number_warn + space;
        state = false;
    }
    if (state == true) {
        msg.innerHTML = goodPassWrd;
        return true;
    }
                
}


function check(){
    typeBox = true;
    let msg = document.getElementById("checkBox");
    msg.innerHTML = ``;
}