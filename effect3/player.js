let player = document.querySelector("video");
let playlist = [];

var currentTrack = 1;

//////// Event Listener
document.querySelector("ol").addEventListener("change", e => {
  updatePlaylist();
});

player.addEventListener("ended", e => {
  playerPlayBackground();
});

document.querySelector("body").addEventListener("keydown", e => {
  if (e.keyCode === 39) {
    // right arrow key
    playerPlayNext();
  }
});

//////// Helper Function
function updatePlaylist() {
  // clear all playlist
  playlist = [];

  // get items from input boxes and add to playlist
  let inputs = document.querySelectorAll("input");

  for (let i = 0; i < inputs.length; i++) {
    let path = inputs[i].value.split("\\");
    let filename = path.slice(-1)[0];
    // console.log(inputs[i].value.length);

    // filter non-chosen file
    // http://127.0.0.1:8887/ is "Web Server for Chrome"'s default ip:port
    if (inputs[i].value.length <= 0) continue;
    playlist.push("http://127.0.0.1:8887/" + filename);
  }

  // console.log(playlist);
  currentTrack = -1;
  playerPlayNext();
}

function playerPlayNext() {
  player.src = playlist[currentTrack + 1];
  player.load();
  player.play();

  currentTrack = (currentTrack + 1) % (playlist.length - 1);
}

function playerPlayBackground() {
  player.src = playlist[0];
  player.load();
  player.play();
}

