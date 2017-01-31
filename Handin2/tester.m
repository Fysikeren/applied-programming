function main
  A = [1 + 2i, 2 + 1i, 3 + 3i;
       0 + 1i, 1 + 6i, 4 + 0i;
       5 + 6i, 6 + 5i, 0 + 2i]

  exp(A)
  CalculateExponential(A,50)

  B = [2 + 3i, 0 + 0i, 0 + 0i;
       0 + 0i, 4 + 5i, 0 + 0i;
       0 + 0i, 0 + 0i, 6 + 7i]

  exp(B)
  CalculateExponential(B,50)
end

function res = CalculateExponential(A, nMax)
  res = 0;
  for n = 0:nMax
    res = res + (A^n)/factorial(n);
  end
end