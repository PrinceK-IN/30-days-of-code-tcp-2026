const cells = document.querySelectorAll('.cell');
const statusDisplay = document.getElementById('status');
const modal = document.getElementById('modal');
const resultText = document.getElementById('result-text');

let currentPlayer = "X";
let board = ["", "", "", "", "", "", "", "", ""];
let active = true;

const xIcon = `<svg viewBox="0 0 24 24" fill="none" stroke-width="3"><path class="path-x" d="M18 6L6 18M6 6l12 12"/></svg>`;
const oIcon = `<svg viewBox="0 0 24 24" fill="none" stroke-width="3"><circle class="path-o" cx="12" cy="12" r="9"/></svg>`;

function handleCellClick(e) {
    const idx = e.target.dataset.index;
    if (board[idx] !== "" || !active) return;

    board[idx] = currentPlayer;
    e.target.innerHTML = currentPlayer === "X" ? xIcon : oIcon;
    
    if (checkWin()) {
        endGame(`WINNER: ${currentPlayer}`);
    } else if (board.every(c => c !== "")) {
        endGame("BUFFER OVERFLOW: DRAW");
    } else {
        currentPlayer = currentPlayer === "X" ? "O" : "X";
        statusDisplay.innerText = `WAITING FOR ${currentPlayer}`;
    }
}

function checkWin() {
    const wins = [[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]];
    return wins.some(comb => comb.every(i => board[i] === currentPlayer));
}

function endGame(msg) {
    active = false;
    resultText.innerText = msg;
    setTimeout(() => modal.classList.remove('hidden'), 500);
}

function resetGame() {
    board = ["", "", "", "", "", "", "", "", ""];
    active = true;
    currentPlayer = "X";
    cells.forEach(c => c.innerHTML = "");
    modal.classList.add('hidden');
    statusDisplay.innerText = "READY";
}

cells.forEach(c => c.addEventListener('click', handleCellClick));
document.getElementById('reboot-btn').addEventListener('click', resetGame);

const binaryDisplay = document.getElementById('binary-stream');
setInterval(() => {
    let binary = "";
    for(let i=0; i<6; i++) {
        binary += Math.round(Math.random());
    }
    binaryDisplay.innerText = binary;
}, 500);