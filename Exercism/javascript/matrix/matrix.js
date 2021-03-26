export class Matrix {
  rows = new Array();
  columns = new Array();
  
  constructor(s_input_matrix) {
    for (let s_row of s_input_matrix.split('\n')) {
      this.rows.push(Array.from(s_row.split(' '), x => Number(x)));
    }
  
    let n = this.rows.length;
    let m = this.rows[0].length;
    for (let i = 0; i < m; i++) {
      let col = new Array(n);
      for (let j = 0; j < n; j++) {
        col[j] = this.rows[j][i];
      }
      this.columns.push(col);
    }
  }

  get rows() {
    return this.rows;
  }

  get columns() {
    return this.columns;
  }
}
