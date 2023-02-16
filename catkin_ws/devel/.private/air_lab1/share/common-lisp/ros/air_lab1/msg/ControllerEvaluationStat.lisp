; Auto-generated. Do not edit!


(cl:in-package air_lab1-msg)


;//! \htmlinclude ControllerEvaluationStat.msg.html

(cl:defclass <ControllerEvaluationStat> (roslisp-msg-protocol:ros-message)
  ((samples
    :reader samples
    :initarg :samples
    :type cl:integer
    :initform 0)
   (last_error
    :reader last_error
    :initarg :last_error
    :type cl:float
    :initform 0.0)
   (average_error
    :reader average_error
    :initarg :average_error
    :type cl:float
    :initform 0.0))
)

(cl:defclass ControllerEvaluationStat (<ControllerEvaluationStat>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ControllerEvaluationStat>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ControllerEvaluationStat)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name air_lab1-msg:<ControllerEvaluationStat> is deprecated: use air_lab1-msg:ControllerEvaluationStat instead.")))

(cl:ensure-generic-function 'samples-val :lambda-list '(m))
(cl:defmethod samples-val ((m <ControllerEvaluationStat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader air_lab1-msg:samples-val is deprecated.  Use air_lab1-msg:samples instead.")
  (samples m))

(cl:ensure-generic-function 'last_error-val :lambda-list '(m))
(cl:defmethod last_error-val ((m <ControllerEvaluationStat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader air_lab1-msg:last_error-val is deprecated.  Use air_lab1-msg:last_error instead.")
  (last_error m))

(cl:ensure-generic-function 'average_error-val :lambda-list '(m))
(cl:defmethod average_error-val ((m <ControllerEvaluationStat>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader air_lab1-msg:average_error-val is deprecated.  Use air_lab1-msg:average_error instead.")
  (average_error m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ControllerEvaluationStat>) ostream)
  "Serializes a message object of type '<ControllerEvaluationStat>"
  (cl:let* ((signed (cl:slot-value msg 'samples)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'last_error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'average_error))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ControllerEvaluationStat>) istream)
  "Deserializes a message object of type '<ControllerEvaluationStat>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'samples) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'last_error) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'average_error) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ControllerEvaluationStat>)))
  "Returns string type for a message object of type '<ControllerEvaluationStat>"
  "air_lab1/ControllerEvaluationStat")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ControllerEvaluationStat)))
  "Returns string type for a message object of type 'ControllerEvaluationStat"
  "air_lab1/ControllerEvaluationStat")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ControllerEvaluationStat>)))
  "Returns md5sum for a message object of type '<ControllerEvaluationStat>"
  "46c88f67df59b89f4eac2f8df597d291")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ControllerEvaluationStat)))
  "Returns md5sum for a message object of type 'ControllerEvaluationStat"
  "46c88f67df59b89f4eac2f8df597d291")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ControllerEvaluationStat>)))
  "Returns full string definition for message of type '<ControllerEvaluationStat>"
  (cl:format cl:nil "int32 samples           # Number of samples used for computing the error~%float64 last_error      # Last error~%float64 average_error   # Average error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ControllerEvaluationStat)))
  "Returns full string definition for message of type 'ControllerEvaluationStat"
  (cl:format cl:nil "int32 samples           # Number of samples used for computing the error~%float64 last_error      # Last error~%float64 average_error   # Average error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ControllerEvaluationStat>))
  (cl:+ 0
     4
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ControllerEvaluationStat>))
  "Converts a ROS message object to a list"
  (cl:list 'ControllerEvaluationStat
    (cl:cons ':samples (samples msg))
    (cl:cons ':last_error (last_error msg))
    (cl:cons ':average_error (average_error msg))
))
