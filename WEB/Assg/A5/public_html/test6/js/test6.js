function AddImage() 
{
  var img = document.createElement('img');
  img.src = 'images/logo.png';
  img.setAttribute('width', '25%');
  img.setAttribute('height', '25%');

  var imageID = document.getElementById('imageID')
  imageID.appendChild(img);
}

function AddTable() {
  var tbl = document.createElement('table');
  tbl.setAttribute('border', '1px solid black');

  tbl.innerHTML = 
  `<thead>
  <tr>
      <th>First Name</th>
      <th>Last Name</th>
      <th>Age</th>
      <th>Email</th>
  </tr>
  </thead>
  <tbody>
  <tr>
      <td>Kaitlin</td>
      <td>Burns</td>
      <td>23</td>
      <td>kburns99753@usermail.com</td>
  </tr>
  <tr>
      <td>Joshua</td>
      <td>Feir</td>
      <td>31</td>
      <td>josh319726@usermail.com<br></td>
  </tr>
  </tbody>`
  document.getElementById('tableID').appendChild(tbl);
}
function Congrats() 
{
  document.getElementById('congratID').style.color='red'
  var text = document.querySelector("#congratID");
  text.innerHTML = "Congrats!";
}