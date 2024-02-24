program hello
  !$omp parallel
  print *, 'Hello, World!'
  !$omp end parallel
  stop
end program hello
