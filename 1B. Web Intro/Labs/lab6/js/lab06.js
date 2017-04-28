// Name: DJ
// set a global httpRequest object

var httpRequest;

// TODO: when the page (window) has loaded, make a
// request for page 1

window.onload = function() {
  makeRequest(1);
  
};
function makeRequest(pageNum) {

    // TODO: create a variable "url" to store the request to
	// the current pageNum, ie:
	//
	// "http://reqres.in/api/users?page=1" // for page 1
	// "http://reqres.in/api/users?page=2" // for page 2
	// etc...

  	var path = "http://reqres.in/api/users?page="+pageNum;

	// make an HTTP request object

	httpRequest = new XMLHttpRequest();

	// show an alert if we were unable to make an XMLHttpRequest object

	if (!httpRequest) {
		alert('Cannot create an XMLHTTP instance');
		return false;
	}

	// execute the "showContents" function when
	// the httprequest.onreadystatechange event is fired

	httpRequest.onreadystatechange = showContents;

	// open a asynchronous HTTP (GET) request with the specified url

	httpRequest.open('GET', path, true);

	// send the request

	httpRequest.send();
}

// the function that handles the server response

function showContents() {

//  check for response state
//  0      The request is not initialized
//  1      The request has been set up
//  2      The request has been sent
//  3      The request is in process
//  4      The request is complete

	if (httpRequest.readyState === 4) {
		// check the response code

		if (httpRequest.status === 200) { // The request has succeeded
		// Javascript function JSON.parse to parse JSON data

			var jsData = JSON.parse(httpRequest.responseText);
			
			// TODO: use the jsData object to populate the correct
			// table cells, ie <tr><td>...</td></tr>
			// in the <tbody> element with id="data"
			
			var tablebody = document.getElementById('data');	
			tablebody.innerHTML="";
			
			for(var i=0;i<jsData.per_page;i++){


					var row = tablebody.insertRow(i);
					var text_id = document.createTextNode(jsData.data[i].id);
					var text_name = document.createTextNode(jsData.data[i].first_name);
					var text_last = document.createTextNode(jsData.data[i].last_name);
					var image_url = jsData.data[i].avatar;
					var cell_id = document.createElement("td");
					var cell_name = document.createElement("td");
					var cell_last = document.createElement("td");
					var cell_image = document.createElement("img");
					cell_image.setAttribute("src",image_url);	
					cell_id.appendChild(text_id);
					cell_name.appendChild(text_name);
					cell_last.appendChild(text_last);
					tablebody.appendChild(row);
					row.appendChild(cell_id);
					row.appendChild(cell_name);
					row.appendChild(cell_last);
					row.appendChild(cell_image);

				
	
			}

			// TODO: remove the class "active" from all elements with the class "pgbtn"

			var removeclass = document.getElementsByClassName("pgbtn");

			for(var i=0;i<removeclass.length;i++)
				removeclass[i].classList.remove("active");
			

			// TODO: add the class "active" to the button corresponding to the active page, ie:
			//
			// if jsData.page is 1, add the class "active" to button element with id pgbtn1
			// if jsData.page is 2, add the class "active" to button element with id pgbtn2
			// etc...
		
			var addClass = document.querySelector("#pgbtn"+jsData.page);
			addClass.classList.add("active");

		} else {
			alert('There was a problem with the request.');
		}
	}
}
