
(cl:in-package :asdf)

(defsystem "air_lab3-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ExecuteTst" :depends-on ("_package_ExecuteTst"))
    (:file "_package_ExecuteTst" :depends-on ("_package"))
  ))