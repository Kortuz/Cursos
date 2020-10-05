#lang play
(require "T1.rkt")

(print-only-errors #t)

;; Parte b)
(test (eval (simple 2)) 2)
(test (eval (compound 3 4 (simple 2))) 5)

;; Parte c)
(test (degree (compound 3 4 (simple 2))) 1)
(test (degree (simple 1232163)) 0)
(test (degree (compound 8 7 (compound 3 4 (simple 2)))) 2)

;; Parte d)
(test ((fold identity +) (compound 3 4 (simple 2))) (+ 3 4 2))
(test ((fold identity *) (compound 10 29 (simple 35))) (* 10 29 35))
(test ((fold / *) (compound 1 2 (simple 3))) (* 1 2 (/ 3))) 

;; Parte e)
(test (eval2 (simple 2)) 2)
(test (eval2 (compound 3 10 (simple 2))) 8)
(test (eval2 (compound 3 39 (compound 3 10 (simple 1)))) 6)

(test (degree2 (compound 3 4 (simple 20))) 1)
(test (degree2 (compound 3 4 (compound 3 4 (compound 3 4 (simple 2))))) 3)
(test (degree2 (simple 10)) 0)

;; Parte f)
(test (mysterious-cf 0) (simple 3))
(test (mysterious-cf 2) (compound 3 1 (compound 6 9 (simple 6))))
(test (mysterious-cf 3) (compound 3 1 (compound 6 9 (compound 6 25 (simple 6)))))
(test/exn (mysterious-cf -1) "Error:argumento negativo")

;; Parte g)
(test (from-to 1 1) '(1))
(test (from-to 0 3) '(0 1 2 3))

(test (mysterious-list 0) '())
(test (mysterious-list 2) (cons 3.0 (cons (+ 3.0 (/ 1.0 6.0)) (cons (+ 3.0 (/ 1.0 (+ 6 (/ 9 6)))) '()))))

;; Parte h)
(test (rac-to-cf 3) (simple 3))
(test (rac-to-cf (+ 3 49/200)) (compound 3 1 (compound 4 1 (compound 12 1 (simple 4)))))






