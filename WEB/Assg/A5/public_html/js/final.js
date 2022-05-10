var courseList = [
    {
        courseCode: "BTP100", courseName: "Programming Fundamentals Using C",
        courseOutline: "https://ict.senecacollege.ca/course/btp100"
    },
    {
        courseCode: "BTI225", courseName: "Web Programming Principles",
        courseOutline: "https://ict.senecacollege.ca/course/bti225"
    },
    {
        courseCode: "BTI325", courseName: "Web Programming Tools and Frameworks",
        courseOutline: "https://ict.senecacollege.ca/course/bti325"
    },
    {
        courseCode: "BTI425", courseName: "Web Programming for Apps and Services",
        courseOutline: "https://ict.senecacollege.ca/course/bti425"
    }
];

function search() {
    let table = document.createElement("table");
    table.setAttribute("id", "table_outline")
    table.innerHTML = `
        <tr>
            <th>
                Course Code
            </th>
            <th>
                Course Name
            </th>
            <th>
                Course Outline
            </th>
        </tr>`;

    let container = document.getElementById("searchResult");
    container.innerHTML = "";

    let search = document.getElementById("courseCode");
    let valid = false;
    let bool = false;

    if (search.value.length == 0) {
        for (let i = 0; i < courseList.length; i++) {
            let input = document.createElement("tr");
            input.innerHTML = `
                    <td>
                        ${courseList[i].courseCode}
                    </td>
                    <td>
                        ${courseList[i].courseName}
                    </td>
                    <td>
                        ${courseList[i].courseOutline}
                    </td>
            `
            table.appendChild(input);
        }
        bool = true;
    }
    else {
        for (let i = 0; i < courseList.length; i++) {
            var searchTemp = courseList[i].courseCode;
            var valueTemp = search.value;
            if (searchTemp.toLowerCase().includes(valueTemp.toLowerCase())) {
                let input = document.createElement("tr");
                input.innerHTML = `
                        <td>
                            ${courseList[i].courseCode}
                        </td>
                        <td>
                            ${courseList[i].courseName}
                        </td>
                        <td>
                            ${courseList[i].courseOutline}
                        </td>
                `
                table.appendChild(input);
                valid = true;
            }
        }
    }

    container.appendChild(table);

    if (valid == false && bool == false) {
        resetMSG();
    }
}

function resetMSG() {
    let container = document.getElementById("searchResult");
    container.innerHTML = ` `;
}

function isNumber(input) {
    var bool = false
    for (let i = -1; i < 16; i++) {
        if (!isNaN(parseInt(input[i - 1]))) {
            bool = true;
        }
    }
    return bool;
}
function isSpecialCharacter(input) {
    var format = /[!@#$%^&*()_+\-=\[\]{};:"\\|,.<>\/?]/; //not include ' and " " in this 
    if (input.match(format)) {
        return true;
    } else {
        return false;
    }
}
function validation() {
    var input = document.getElementById("name").value
    let msg = document.getElementById("msg");
    msg.innerHTML = "";
    if (!isNumber(input) && !isSpecialCharacter(input)) {
        msg.innerHTML = "";
    }
    else {
        msg.innerHTML += "<b>Validation: </b> Allowed characters only include: alphabet letters (lowercase or uppercase),apostrophe(‘), and white space( )."
    }
}