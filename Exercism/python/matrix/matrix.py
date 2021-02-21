class Matrix:
    def __init__(self, matrix_string):
        self._row = [[int(i_s) for i_s in r_s] for r_s in
            [line_s.split(' ') for line_s in matrix_string.splitlines()]]

        self._column = [[r[i] for r in self._row] for i in
            range(0, len(self._row[0]))]

    def row(self, index):
        return self._row[index-1]

    def column(self, index):
        return self._column[index-1]
