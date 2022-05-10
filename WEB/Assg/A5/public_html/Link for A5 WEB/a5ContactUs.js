
function Validate() {

}

function userNameValidate() {
    let userName = document.getElementById("userName");
    let valid = true;
    if (userName.length > 0) {
        for (let i = 0; i < userName.length; i++) {
            if (!isLetter(userName[i])) {
                valid = false;
            }
        }
        if (userName[0].toUpperCase() != userName[0]) {
            valid  = false;
        }
    }
    else {
        valid = false;
    }
    return valid;
}