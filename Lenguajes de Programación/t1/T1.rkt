#lang play
(require math/flonum)

#|
Complete sus datos personales:
NOMBRE Y APELLIDO:Sebastian Cortes
RUT: 19.995.956-5
|#

;; Parte a)
;; Definicion de tipo para fracciones continuas
;;<CFraction> ::= (simple <value>)
;;                |(compound <value> <value> <cFraction>)
(deftype cFraction
  (simple a)
  (compound a b d))

;; Parte b)
;; eval :: CFraction -> Rational
;; Transforma una fraccion continua en su forma racional
(define (eval x)
  (match x
        [(simple c) (identity c)]
        [(compound a b d) (+ a (/ b (eval d)))]))

;; Parte c)
;; degree ::  CFraction -> Integer
;; Devuelve el grado de una fraccion continua
(define (degree x)
  (match x
    [(simple a) 0]
    [(compound a b c) (+ 1 (degree c))]))

;; Parte d)
;; fold :: (Integer -> A) (Integer Integer A -> A) -> (CFraction -> A)
;; Captura el esquema de recursion asociado a las fracciones continuas
(define (fold f g)
  (λ (cf)
    (match cf
        [(simple a) (f a)]
        [(compound a b d) (g a b ((fold f g) d))])))

;; Parte e)
;; eval2 :: CFraction -> Rational
;; Transforma una fraccion continua en su forma racional usando fold
(define eval2
    (fold identity (λ (a b d)(+ a(/ b d)))))

;; degree2 ::  CFraction -> Integer
;; Devuelve el grado de una fraccion continua usando fold
(define degree2
  (fold (λ (a) (+ 0)) (λ (a b d) (+ 1 d))))

;; Parte f)
;; mysterious-cf :: Integer -> CFraction
;; Devuelve una fraccion continua tipo mysterious del grado que se le pase. Devuelve error cuando se le pase un negativo
(define (mysterious-cf x [args '()])
  (if (> 0 x)
      (error "Error:argumento negativo")
      (if (equal? args '())
          (if (= x 0)
              (simple 3)
              (compound 3 1 (mysterious-cf (- x 1) 1)))
          (if (= x 0)
              (simple 6)
              (compound 6 (* (+ args 2) (+ args 2)) (mysterious-cf (- x 1) (+ args 2)))))))

;; Parte g)
;; from-to :: Integer Integer -> listOf Integer
;; Devuelve una lista de los enteros comprendidos entre los enteros(incluidos estos)
(define (from-to a b)
  (if (= a b)
      (cons a '())
      (cons a (from-to (+ a 1) b))))

;; mysterious-list :: Integer -> listOf Float
;; Entrega una lista de n floats que describen los valores (en decimales) de los n primeros mysterious-cf. Cero devuelve lista vacia
(define (mysterious-list a)
  (if (= a 0)
      '()
      (let ([x (from-to 0 a)])
        (map fl (map eval (map mysterious-cf x))))))

;; A que numero tiende (mysterious-cf k) cuando k tiende a infinito?
;;(print (mysterious-list 20)) -> '(3.0 3.1666666666666665 3.1333333333333333 ....... 3.141623806667839 3.1415657346585473)
;; El numero tiende a pi (3,1416...) cuando k tiende a infinito :O

;; Parte h)
;; rac-to-cf :: Rational -> CFraction
;; Devuelve la representacion en fraccion continua de un numero racional no-negativo
(define (rac-to-cf x)
  (if (= 0 (- x (floor x)))
      (simple x)
      (compound (floor x) 1 (rac-to-cf (/ 1 (- x (floor x)))))))
